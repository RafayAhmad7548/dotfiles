package com.rutils;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.net.http.HttpRequest.BodyPublishers;
import java.net.http.HttpResponse.BodyHandlers;
import java.security.KeyStore;

import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManagerFactory;


public class HttpsUtil{

    static HttpClient client;

    static{
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

    public static int registerUser(String username, String password, String passwordAgain){
        if(password != passwordAgain) return 0;
        else{
            String jsonPayload = String.format("{\"username\":\"%s\", \"password\":\"%s\"}", username, password);

            try{
                HttpRequest request = HttpRequest.newBuilder()
                    .uri(new URI("https://localhost:8000/register"))
                    .header("Content-Type", "application/json")
                    .POST(BodyPublishers.ofString(jsonPayload))
                    .build();
                
                HttpResponse<String> response = client.send(request, BodyHandlers.ofString());
            }
            catch(URISyntaxException e){
                e.printStackTrace();
            }
            catch (IOException e){
                e.printStackTrace();
            }
            catch (InterruptedException e){
                e.printStackTrace();
            }
        }       

        return 0;
    }

    public static int verifyCredentials(String username, String password){
        try{
            String jsonPayload = String.format("{\"username\":\"%s\", \"password\":\"%s\"}", username, password);

            HttpRequest request = HttpRequest.newBuilder()
                .uri(new URI("https://localhost:8000/login"))
                .header("Content-Type", "application/json")
                .POST(BodyPublishers.ofString(jsonPayload))
                .build();

            HttpResponse<String> httpResponse = client.send(request, BodyHandlers.ofString());
            
            int response = Integer.parseInt(httpResponse.body());
            return response;
        }
        catch(URISyntaxException e1){
            System.err.println("Invalid Uri provided for http request");
            e1.printStackTrace();
        }
        catch(InterruptedException e2){
            System.err.println("sending request interuppterd Eroor");
            e2.printStackTrace();
        }
        catch(IOException e3){
            System.err.println("io exeception when sending http request");
            e3.printStackTrace();
        }
        
        return 0;
    }
}