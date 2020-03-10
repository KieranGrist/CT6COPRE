using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class B_Apache : MonoBehaviour
{
   public ApacheEngine RightEngine;
    public ApacheEngine LeftEngine;
    public Cockpit Cockpit;
    public ApacheMainRotor MainRotor;
    public ApacheTailRotor TailRotor;
    public Rigidbody FlightPhysics;
    // Start is called before the first frame update
    void Start()
    {
        FlightPhysics = GetComponent<Rigidbody>();
        Cockpit.Apache = this;
        Cockpit.Collective.Apache = this;
        Cockpit.Joystick.Apache = this;
        MainRotor.Apache = this;
        TailRotor.Apache = this;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
