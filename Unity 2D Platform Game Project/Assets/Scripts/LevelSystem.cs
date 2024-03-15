using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class LevelSystem : MonoBehaviour {
    public static string actualLevel = "Nivel 1";
    public string nextLevel;

    void Start() {
        actualLevel = SceneManager.GetActiveScene().name;
    }

    private void OnTriggerEnter2D(Collider2D collider) {
        if (collider.CompareTag("Player"))
            SceneManager.LoadScene(nextLevel); 
    }
}
