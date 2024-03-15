using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour {
    public GameObject player;
    public string shootDirection; //Left, Right, Up

    void Update() {
        if (shootDirection == "Right")
            transform.position = new Vector2(player.transform.position.x + 1.2f, player.transform.position.y - 0.611658f);
        else if (shootDirection == "Left")
            transform.position = new Vector2(player.transform.position.x - 1.2f, player.transform.position.y - 0.611658f);
        else if (shootDirection == "Up")
            transform.position = new Vector2(player.transform.position.x, player.transform.position.y + 0.6f);
    }
}