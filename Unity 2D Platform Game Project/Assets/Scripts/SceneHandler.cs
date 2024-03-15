/*
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SceneHandler : MonoBehaviour {
    [SerializeField] ReactTransform fader;
    
    public void Start() {
        fader.gameObject.SetActive(true);
        
        LeanTween.scale(fader, new Vector3(1, 1, 1), 0);
        LeanTween.scale(fader, Vector3.zero, 0.5f).setOnComplete(() => {
            fader.gameObject.SetActive(false);
        });
    }
    public void OpenMenuScene() {
        fader.gameObject.SetActive(true);

        LeanTween.scale(fader, Vector3.zero, 0f);
        LeanTween.scale(fader, new Vector3 (1, 1, 1), 0.5f).setOnComplete(() => {
            SceneManager.LoadScene(0);
        });
    }

    public void OpneGameScene() {
        fader.gameObject.SetActive(true);

        LeanTween.scale(fader, Vector3.zero, 0f);
        LeanTween.scale(fader, new Vector3 (1, 1, 1), 0.5f).setOnComplete(() => {
            SceneManager.LoadScene(1);
        });
    }
}
*/