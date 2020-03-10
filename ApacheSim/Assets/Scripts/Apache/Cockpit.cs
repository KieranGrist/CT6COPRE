using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cockpit : MonoBehaviour
{
 public   B_Apache Apache;
    // Sets default values for this actor's properties
    public EngineSwitch LeftEngineSwitch;
    public  EngineSwitch RightEngineSwitch;
    public  RotorBreakSwitch RotorBreakSwitch;
    public  ApacheJoystick Joystick;
    public  ApacheCollective Collective;
    public float Speed = 0;
    public float Height = 0;
    // Start is called before the first frame update
    void Start()
    {
        Joystick.Apache = Apache;
        Collective.Apache = Apache;
        RightEngineSwitch.ApacheEngine = Apache.RightEngine;
        LeftEngineSwitch.ApacheEngine = Apache.LeftEngine;

    }

    // Update is called once per frame
    void Update()
    {
        Speed = Apache.FlightPhysics.velocity.magnitude;

        Vector3 Loc = Apache.transform.position;
        if (Physics.Raycast(transform.position, -transform.up, out RaycastHit hitinfo, float.PositiveInfinity))
        {
            Height = Vector3.Distance(Apache.transform.position, hitinfo.transform.position);
            Height -= 28.685221f;
        }
    }
}
