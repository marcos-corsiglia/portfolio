using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class TriggerSpikes : MonoBehaviour {
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