using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Menucontroller : MonoBehaviour {
    public GameObject[] buttons; 
    private int actualButton; 

    void Start() {
        actualButton = 1;
        transform.parent = buttons[actualButton - 1].transform;
        transform.position = new Vector2(transform.parent.position.x - 500f, transform.parent.position.y + 52f);
    }
    
    void Update() {
        if (Input.GetKeyDown(KeyCode.S))
            positionOnButton(true);
        else if (Input.GetKeyDown(KeyCode.W))
            positionOnButton(false);
        else if (Input.GetKeyDown(KeyCode.Space))
            cargarEscena();
    }

    void positionOnButton(bool down) {
        // Pongo al personaje a una posicion X y a una posicion Y del boton en particular
        
        if (down && actualButton < buttons.Length) 
            actualButton++;
        else if (down && actualButton == buttons.Length) 
            actualButton = 1;
        else if (!down && actualButton > 1)
            actualButton--;
        else if (!down && actualButton == 1)
            actualButton = buttons.Length;

        transform.parent = buttons[actualButton - 1].transform;
        transform.position = new Vector2(transform.parent.position.x - 500f, transform.parent.position.y + 52f);
    }

    void cargarEscena() {
        if (transform.parent.name == "Play")
            SceneManager.LoadScene("Nivel 1");
        else if (transform.parent.name == "Exit Game")
            Application.Quit();
        else if (transform.parent.name == "Try Again")
            SceneManager.LoadScene(LevelSystem.actualLevel);
        else if (transform.parent.name == "Main Menu")
            SceneManager.LoadScene("Main Menu");
    }
}