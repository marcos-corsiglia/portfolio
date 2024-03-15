using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Bullet : MonoBehaviour {
    public float bulletSpeed = 50f;
    public GameObject player;
    public string shootPosition;

    void Start() {
        Destroy(gameObject, 3);
    } 

    void Update() {
        if (shootPosition == "Right")
            transform.Translate(Vector2.right * bulletSpeed * Time.deltaTime);
        else if (shootPosition == "Left")
            transform.Translate(Vector2.left * bulletSpeed * Time.deltaTime);
        else if (shootPosition == "Up")
            transform.Translate(Vector2.up * bulletSpeed * Time.deltaTime);

    }

    private void OnTriggerEnter2D(Collider2D collider) {
        EnemyPatrol enemyPatrol = collider.GetComponent<EnemyPatrol>();
        FinalBoss finalBoss = collider.GetComponent<FinalBoss>();

        if (enemyPatrol != null && collider.CompareTag("Enemy")) {
            if (enemyPatrol.life > 1) {
                enemyPatrol.life--;
            }
            else {
                Destroy(collider.gameObject);
            }
        }
        else if (finalBoss != null && collider.CompareTag("Boss")) {
            if (finalBoss.life > 1) {
                finalBoss.life--;
            }
            else {
                Destroy(collider.gameObject);
                SceneManager.LoadScene("Game Finished");
            }   
        }
        
        Destroy(gameObject); 
    }
}
