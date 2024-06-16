package com.rutils;

import java.io.IOException;

import org.jnativehook.GlobalScreen;
import org.jnativehook.NativeHookException;
import org.jnativehook.keyboard.NativeKeyEvent;
import org.jnativehook.keyboard.NativeKeyListener;

public class GlobalKeyListener implements NativeKeyListener{
    public void nativeKeyPressed(NativeKeyEvent e){
        if(e.getKeyCode() == NativeKeyEvent.VC_SHIFT){
            System.out.println("Shift pressed");
            try{
                ProcessBuilder builder = new ProcessBuilder("firefox");
                Process process = builder.start();
                process.waitFor();
            }
            catch(IOException e1){
                e1.printStackTrace();
            }
            catch(InterruptedException e2){
                e2.printStackTrace();
            }

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
            Thread.sleep(3000);
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