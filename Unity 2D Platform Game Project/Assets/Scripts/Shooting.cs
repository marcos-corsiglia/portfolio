using UnityEngine;

public class ShootController : MonoBehaviour {
    public GameObject bulletPrefab; 
    public string shootDirection; //Left, Right, Up

    void Update() {
        if ( (Input.GetKeyDown(KeyCode.L) && shootDirection == "Right")
            || (Input.GetKeyDown(KeyCode.J) && shootDirection == "Left")
            || (Input.GetKeyDown(KeyCode.I) && shootDirection == "Up") ) {
            GameObject newBullet = Instantiate(bulletPrefab, transform.position, Quaternion.identity);
            Bullet bullet = newBullet.GetComponent<Bullet>();
            bullet.shootPosition = shootDirection;
        }

    }
}