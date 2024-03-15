using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour {
    public float FollowSpeed = 1f;
    public float yOffSet = 1f;
    public Transform target;

    void Update() {
        Vector3 newPos = new Vector3(target.position.x, target.position.y + yOffSet, -10f);
        transform.position = Vector3.Slerp(transform.position, newPos, FollowSpeed * Time.deltaTime);
    }
}