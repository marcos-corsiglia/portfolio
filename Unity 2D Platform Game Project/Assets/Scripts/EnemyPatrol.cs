using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class EnemyPatrol : MonoBehaviour {
    public GameObject pointA;
    public GameObject pointB;
    private Rigidbody2D rb;
    private Animator anim;
    private Transform currentPoint;
    public float speed;
    public int life;
    public bool stay;

    void Start() {
        rb = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
        currentPoint = pointB.transform;
        
        if (stay) {
            anim.SetBool("IsRunning", false);
            Flip();
        }
        else {
            anim.SetBool("IsRunning", true);
        }
    }

    void Update() {
        if (!stay) {
            Vector2 point = currentPoint.position - transform.position;

            if (currentPoint == pointB.transform) {
                rb.velocity = new Vector2(speed, 0);
            }
            else {
                rb.velocity = new Vector2(-speed, 0);
            }
            
            if (Vector2.Distance(transform.position, currentPoint.position) < 0.5f && currentPoint == pointB.transform) {
                currentPoint = pointA.transform;
                Flip();
            }
            else if (Vector2.Distance(transform.position, currentPoint.position) < 0.5f && currentPoint == pointA.transform) {
                currentPoint = pointB.transform;
                Flip();
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