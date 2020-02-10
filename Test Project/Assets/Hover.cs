using UnityEngine;
[System.Serializable]
public class ApacheEngine
{
    public bool IsOn = false;


    public float Power = 0.0f;
    public void EngineOn()
    {

        Power += 0.008f;
        Power = Mathf.Clamp(Power, 0, 50);
    }
    public void EngineOff()
    {
        Power -= 0.08f;
        Power = Mathf.Clamp(Power, 0, 50);
    }
}
[System.Serializable]
public class ApacheCollective
{
    public float Collective;
    public float Power;
    public float Thrust;
    public float PowerToApply = 0;
    public float Multiplier = 1;

}
[System.Serializable]
public class Hover : MonoBehaviour
{
    public ApacheCollective apacheCollective;
    public ApacheEngine LeftEngine, RightEngine;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (LeftEngine.IsOn)        
            LeftEngine.EngineOn();        
        else
            LeftEngine.EngineOff();
        if (RightEngine.IsOn)
            RightEngine.EngineOn();
        else
            RightEngine.EngineOff();


        apacheCollective.Power = LeftEngine.Power + RightEngine.Power;
        apacheCollective.Power = Mathf.Clamp(apacheCollective.Power, 0.0f, 100.0f);
        apacheCollective.Collective = Mathf.Clamp(apacheCollective.Collective, 0.0f, 1.0f);
        apacheCollective.Thrust = apacheCollective.Collective * 100;
        apacheCollective.Thrust = Mathf.Clamp(apacheCollective.Thrust, 0.0F, apacheCollective.Power);


        //Collective = FMath::Lerp(Collective, .515f, DeltaTime);

        //0 = -0.5, 50 = 0, 100 = 0.5 

        apacheCollective.PowerToApply = 0;
        apacheCollective.PowerToApply = apacheCollective.Thrust - apacheCollective.Power * .5f;
        apacheCollective.PowerToApply *= apacheCollective.Multiplier;
        apacheCollective.PowerToApply *= Time.deltaTime;



        Collective = FMath::Lerp(Collective, .515f, DeltaTime);


        if (Apache->MainRotor->ApacheRotor->PropellorRotation > 6)
        {
            Apache->Body->AddForce(FVector(Apache->GetActorUpVector() * PowerToApply));

        }
        else
            NoPower(DeltaTime);

        if (!PhysicsRef)
        {
            TArray<UPrimitiveComponent*> Array;
            Apache->GetComponents(Array);
            if (Array[0])
                PhysicsRef = Array[0];
        }
    }
}
