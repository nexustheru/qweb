# qweb
htlm ultralightrender with net bridge

a tiny net bridge between https://github.com/ultralight-ux/Ultralight and net,made an api to use ultra,the bridge is the net version interop one, makes more simpler

UNity version runtime, put resources direcly into unity folder, and the native ones in plugins folder

using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UIElements;
using System.Runtime.InteropServices;
using System;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;
using qwebBridge;
using System.Collections;

public class test : MonoBehaviour, IPointerClickHandler
{
    Ultrabrowse ub;
    void Start()
    {

        try
        {
            ub= new Ultrabrowse();
            ub.init();
            ub.Links = "https://www.google.com/";
            ub.browsetolink();
           
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(ub.LinksLoaded())
        {
            StartCoroutine(sleepforpic());
            ub.takescreenshot();
            Debug.Log("screenshoot taken");
        }
        else
        {
            ub.updates();
        }
        
            
    }
    IEnumerator sleepforpic()
    {
        yield return new WaitForSeconds(10);

    }
    public void OnPointerClick(PointerEventData eventData) // 3
    {
        print("I was clicked");
        Vector3 mousePos = Input.mousePosition;
        Debug.Log(mousePos.x);
        Debug.Log(mousePos.y);
        Debug.Log(mousePos.z);

    }
}

