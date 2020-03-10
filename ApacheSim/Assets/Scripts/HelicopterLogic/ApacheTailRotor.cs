using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ApacheTailRotor : MonoBehaviour
{
    public B_Apache Apache;
    public float PropellorRotation;
    public float RotorTime = .01f;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        PropellorRotation = Mathf.Clamp(PropellorRotation, 0.0f, 7.0f);
        gameObject.transform.Rotate(new Vector3(PropellorRotation, 0, 0));
        if (Apache.Cockpit.LeftEngineSwitch.IsOn && Apache.Cockpit.RotorBreakSwitch.IsOn == false)
            RotateRotor();

        if (Apache.Cockpit.RightEngineSwitch.IsOn && Apache.Cockpit.RotorBreakSwitch.IsOn == false)
            RotateRotor();
        if (Apache.Cockpit.RightEngineSwitch.IsOn && Apache.Cockpit.LeftEngineSwitch.IsOn == false || Apache.Cockpit.RightEngineSwitch.IsOn == false && Apache.Cockpit.LeftEngineSwitch.IsOn)
            PropellorRotation -= RotorTime * 0.9f;

        if (Apache.Cockpit.RotorBreakSwitch.IsOn)
            ApplyBreak();   
    }

    void RotateRotor()
    {
        PropellorRotation += RotorTime;
    }

    void ApplyBreak()
    {
        PropellorRotation -= RotorTime * 2;
    }

}
