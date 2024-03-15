using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class FinalBoss : MonoBehaviour {
    public GameObject pointA;
    public GameObject pointB;
    public GameObject player;
    private Rigidbody2D rb;
    private Animator anim;
    private Transform currentPoint;
    private int lap;
    public int maxLap;
    private bool stay = false;
    private float timer = 0f;
    private float auxPlayerX;
    public float speedX;
    public float speedY;
    public int life;

    void Start() {
        rb = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        currentPoint = pointB.transform;
        auxPlayerX = player.transform.position.x;
        anim.SetBool("IsOnSky", false);
        lap = 0;
    }

    void Update() {
        if (!stay) {
            Vector2 point = currentPoint.position - transform.position;

            if (currentPoint == pointB.transform) {
                rb.velocity = new Vector2(speedX, 0);
            }
            else {
                rb.velocity = new Vector2(-speedX, 0);
            }
            
            if (Vector2.Distance(transform.position, currentPoint.position) < 0.5f && currentPoint == pointB.transform) {
                currentPoint = pointA.transform;
                Flip();
                lap++;
            }
            else if (Vector2.Distance(transform.position, currentPoint.position) < 0.5f && currentPoint == pointA.transform) {
                currentPoint = pointB.transform;
                Flip();
            }

            if (lap == maxLap) {
                stay = true;
                anim.SetBool("IsOnSky", true);
            }
        }
        else if (timer < 5f && stay) {
            timer += Time.deltaTime;
            transform.position = new Vector2(player.transform.position.x, 24.18f);
        }
        else if ( (timer > 5 && timer < 6) && stay) {
            auxPlayerX = player.transform.position.x; 
            timer++;
        }
        else if (timer > 6f && stay) {
            if (transform.position.y > 16.404f) {
                transform.position = new Vector2(auxPlayerX, transform.position.y - speedY * Time.deltaTime);
            }
            else {
                timer = 0f;
                lap = 0;
                stay = false;
                anim.SetBool("IsOnSky", false);
            }
        }

        
    }

    private void Flip() {
        Vector3 localScale = transform.localScale;
        localScale.x *= -1;
        transform.localScale = localScale;
    }

    private void OnDrawGizmos() {
        if (!stay) {
            Gizmos.DrawWireSphere(pointA.transform.position, 0.5f);
            Gizmos.DrawWireSphere(pointB.transform.position, 0.5f);
            Gizmos.DrawLine(pointA.transform.position, pointB.transform.position);
        }
    }
    private void OnTriggerEnter2D(Collider2D collider) {
        if (collider.CompareTag("Player")) {
            collider.gameObject.SetActive(false);
            StartCoroutine(CargaGameOver());
        }
    }

    IEnumerator CargaGameOver() {
        yield return new WaitForSeconds(1f);
        SceneManager.LoadScene("Game Over");
    }
}