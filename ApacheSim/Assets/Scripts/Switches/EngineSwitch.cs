using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EngineSwitch : B_Switch
{
    public ApacheEngine ApacheEngine;
    public override void ActionWhenOff()
    {
        ApacheEngine.IsOn = false;
    }

    public override void ActionWhenOn()
    {
        ApacheEngine.IsOn = true;
    }

    // Start is called before the first frame update
    void Start()
    {
        IsOn = false;
    }

    // Update is called once per frame
    void Update()
    {

        if (IsOn)
            ActionWhenOn();
        else
            ActionWhenOff();

    }
}

