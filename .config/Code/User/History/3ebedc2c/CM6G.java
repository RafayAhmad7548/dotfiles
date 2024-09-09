package com.rutils;

import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.net.http.HttpResponse.BodyHandlers;
import java.security.KeyStore;

import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManagerFactory;


public class HttpsUtil{

    static HttpClient client;

    public static void init(){
        try{
            KeyStore keyStore = KeyStore.getInstance("PKCS12");
            keyStore.load(HttpsUtil.class.getClassLoader().getResourceAsStream("ksclient.p12"), "ksclient7548".toCharArray());

            TrustManagerFactory tmf = TrustManagerFactory.getInstance(TrustManagerFactory.getDefaultAlgorithm());
            tmf.init(keyStore);

            SSLContext sslContext = SSLContext.getInstance("TLS");
            sslContext.init(null, tmf.getTrustManagers(), null);

            client = HttpClient.newBuilder()
                .sslContext(sslContext)
                .build();
        }
        catch(Exception e){
            e.printStackTrace();
        }
        
    }

    public static void sendHttpsReq(HttpRequest request){
        try{
            client.send(request, BodyHandlers.ofString());
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
}