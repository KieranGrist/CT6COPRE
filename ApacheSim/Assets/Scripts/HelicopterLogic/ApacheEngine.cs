using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ApacheEngine : MonoBehaviour
{
  public  bool IsOn = false;
    public float Power = 0.0f;
    public float Damage;
    // Start is called before the first frame update
    void Start()
    {
        IsOn = false;
    }

    // Update is called once per frame
    void Update()
    {
        Power = Mathf.Clamp(Power, 0.0f, 50.0f);

        if (IsOn)
            EngineOn();
        else
            EngineOff();
    }
    void EngineOn()
    {

        Power += 0.025f;
    }

    void EngineOff()
    {
        Power -= 0.08f;
    }
}
