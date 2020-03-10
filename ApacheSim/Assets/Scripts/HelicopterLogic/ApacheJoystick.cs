using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ApacheJoystick : MonoBehaviour
{


    public Vector3 JoystickRotation;


    public float Multiplier;


    public Vector3 ApacheRotation;


    public B_Apache Apache;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        JoystickRotation.x = transform.rotation.eulerAngles.x + -24.176f;
        JoystickRotation.y = transform.rotation.eulerAngles.y + -78.679f;
        JoystickRotation.z = transform.rotation.eulerAngles.z + -26.051f;

        JoystickRotation.x = Mathf.Clamp(JoystickRotation.x, -90.0f, 90.0f);
        JoystickRotation.y = Mathf.Clamp(JoystickRotation.y, -90.0f, 90.0f);
        JoystickRotation.z = Mathf.Clamp(JoystickRotation.z, -90.0f, 90.0f);
        ApacheRotation = JoystickRotation * Multiplier;
        Apache.FlightPhysics.AddTorque(JoystickRotation);
    }



    void PitchUp()
    {
        JoystickRotation.y -= 10;
    }
    void PitchDown()
    {
        JoystickRotation.y += 10;
    }
    void YawRight()
    {
        JoystickRotation.z += 10;
    }
    void awLeft()
    {
        JoystickRotation.z -= 10;
    }
    void RollRight()
    {
        JoystickRotation.x -= 10;
    }
    void RollLeft()
    {
        JoystickRotation.x += 10;
    }
    // Called every frame



}
