using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class B_Switch : MonoBehaviour
{
    public bool IsOn;
    public abstract void ActionWhenOn();

    public  abstract void ActionWhenOff();

}
