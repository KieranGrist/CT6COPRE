using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ApacheCollective : MonoBehaviour
{
    public float Collective;
    public float Power;
    public B_Apache Apache;
    public float Thrust = 0;
    public float PowerToApply = 0;    
    public float Multiplier = 192714653696.0f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Power = Apache.LeftEngine.Power + Apache.RightEngine.Power;
        Power = Mathf.Clamp(Power, 0.0f, 100.0f);
        Collective = Mathf.Clamp(Collective, 0.0f, 1.0f);
        Thrust = Collective * 100;
        Thrust = Mathf.Clamp(Thrust, 0.0F, Power);


        //Collective = FMath::Lerp(Collective, .515f, DeltaTime);

        //0 = -0.5, 50 = 0, 100 = 0.5 

        PowerToApply = 0;
        PowerToApply = Thrust;
        PowerToApply *= Multiplier;
        PowerToApply *= Time.deltaTime;



        if (Apache.MainRotor.PropellorRotation > 6)
        {
            Apache.FlightPhysics.AddForce(Apache.MainRotor.transform.up * PowerToApply);

        }
    }
}
