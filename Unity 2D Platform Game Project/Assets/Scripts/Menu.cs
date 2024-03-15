using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Menu : MonoBehaviour {
    public GameObject levels;

    public void playGame() {
        SceneManager.LoadScene("Nivel 1");
    }

    public void tryAgain() {
        SceneManager.LoadScene(LevelSystem.actualLevel);
    }

    public void loadMainMenu() {
        SceneManager.LoadScene("Main Menu");
    }

    public void QuitGame() {
        Application.Quit();
    }
}
