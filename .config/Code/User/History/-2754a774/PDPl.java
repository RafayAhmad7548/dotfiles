package com.rutils;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;


public class Main{
    public static void main(String[] args){
        HttpsClient client = HttpClient.newHttpClient();
        try{
            HttpRequest request = HttpRequest.newBuilder().uri(new URI("https://localhost:8000/greet")).build();
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            System.out.println(response.body());
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
}