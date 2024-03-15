using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour {    
    public CharacterController2D controller2D;
    private float horizontal;
    private float previousY;
    private float speed = 8f;
    private float jumpingPower = 16f;
    public bool isFacingRight = true;
    public Animator animator;
    private int jumpsLeft;
    private bool canDash = true;
    private bool isDashing;
    private float dashingPower = 24f; 
    private float dashingTime = 0.2f;
    private float dashingCooldown = 1f;

    [SerializeField] private int maxJumps = 2;
    [SerializeField] private Rigidbody2D rb;
    [SerializeField] private Transform groundCheck;
    [SerializeField] private LayerMask groundLayer; 
    [SerializeField] private TrailRenderer tr;

    void Start() {
        previousY = transform.position.y;
        jumpsLeft = maxJumps;
        // Physics2D.IgnoreCollision(GetComponent<Collider2D>(), bulletPrefab.GetComponent<Collider2D>());
    }
    
    void Update() {
        horizontal = Input.GetAxisRaw("Horizontal");

        if (isDashing)
            return;

        if (IsGrounded()) {
            jumpsLeft = maxJumps;
            canDash = true;
        }
            

        if (Input.GetButtonDown("Jump") && jumpsLeft > 1) {
            rb.velocity = new Vector2(rb.velocity.x, jumpingPower);
            animator.SetBool("IsJumping", true);
            jumpsLeft--;
        }

        if (Input.GetKeyDown(KeyCode.K) && !IsGrounded() 
            && (rb.velocity.x > 0 || rb.velocity.x < 0)
            && canDash)
            StartCoroutine(Dash());

        /*
        if (Input.GetButtonUp("Jump") && rb.velocity.y > 0f) 
            rb.velocity = new Vector2(rb.velocity.x, rb.velocity.y * 0.5f);
        */

        CheckJumpStatus();

        Flip();

        animator.SetFloat("Speed", Mathf.Abs(horizontal));
    }

    public int getJumpsLeft() {
        return jumpsLeft;
    }
    public void setJumpsLeft(int _jumpsLeft) {
        jumpsLeft = _jumpsLeft;
    }

    private void FixedUpdate() {
        rb.velocity = new Vector2(horizontal * speed, rb.velocity.y); 
    }

    private bool IsGrounded() {
        return Physics2D.OverlapCircle(groundCheck.position, 0.2f, groundLayer); 
    }

    public void OnLanding() {
        animator.SetBool("IsJumping", false);
    }

    private void CheckJumpStatus() {
        if (transform.position.y > previousY)
            animator.SetBool("IsFalling", false);
        else 
            animator.SetBool("IsFalling", true);

        previousY = transform.position.y;
    }

    private void Flip() {
        if (isFacingRight && horizontal < 0f || !isFacingRight && horizontal > 0f) {
            isFacingRight = !isFacingRight;
            Vector3 localScale = transform.localScale; 
            localScale.x *= -1f;
            transform.localScale = localScale;
        }
    }

    private IEnumerator Dash() {
        canDash = false;
        isDashing = true;
        float auxSpeed = speed;
        speed = 20f;
        float originalGravity = rb.gravityScale;
        rb.gravityScale = 0f;
        rb.velocity = new Vector2(transform.localScale.x * dashingPower, 0f);  
        tr.emitting = true;                                                    
        yield return new WaitForSeconds(dashingTime);
        tr.emitting = false;
        rb.gravityScale = originalGravity;
        isDashing = false;
        speed = auxSpeed;
        yield return new WaitForSeconds(dashingCooldown);          
    }
}
