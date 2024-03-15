using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TriggerJump : MonoBehaviour {
    public Animator animator;
    public GameObject player;
    PlayerMovement playerMovement;
    private Rigidbody2D rb;
    private bool lastPressedJump;

    void Start() {
        playerMovement = player.GetComponent<PlayerMovement>();
        rb = player.GetComponent<Rigidbody2D>();
        lastPressedJump = false;
    }

    void Update() {
        if (Input.GetButtonDown("Jump"))
            lastPressedJump = true;
        else
            lastPressedJump = false;
    }

    private void OnTriggerEnter2D(Collider2D other) {
        animator.SetBool("IsOnGround", true);
    }

    private void OnTriggerExit2D(Collider2D other) {
        animator.SetBool("IsOnGround", false);

        if (!lastPressedJump && rb.velocity.y == 0) 
            playerMovement.setJumpsLeft(3);
    }
}
