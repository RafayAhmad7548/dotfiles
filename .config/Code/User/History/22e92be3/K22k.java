package com.rutils;

import org.jnativehook.GlobalScreen;
import org.jnativehook.NativeHookException;
import org.jnativehook.keyboard.NativeKeyEvent;
import org.jnativehook.keyboard.NativeKeyListener;

public class GlobalKeyListener implements NativeKeyListener{
    public void nativeKeyPressed(NativeKeyEvent e){
        if(e.getKeyCode() == NativeKeyEvent.VC_SHIFT){
            System.out.println("Shift key pressed");
        }
    }

    public void nativeKeyReleased(NativeKeyEvent e){}
    public void nativeKeyTyped(NativeKeyEvent e){}

    GlobalKeyListener(){
        try{
            GlobalScreen.registerNativeHook();
        }
        catch(Exception ex){
            System.err.println("There was a problem registering the native hook.");
            System.err.println(ex.getMessage());
            System.exit(1);
        }

        GlobalScreen.addNativeKeyListener(this);

        try{
            Thread.sleep(5000);
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }

        GlobalScreen.removeNativeKeyListener(this);

        try{
            GlobalScreen.unregisterNativeHook();
        }
        catch(NativeHookException e){
            e.printStackTrace();
        }

    }

    public static void main(String[] args){
        new GlobalKeyListener();
    }
}