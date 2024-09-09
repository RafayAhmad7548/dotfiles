package com.rutils;

import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.net.http.HttpResponse.BodyHandlers;


public class Main{
    public static void main(String[] args){
        
        try{
            HttpClient client = HttpClient.newBuilder().build();

            HttpRequest request = HttpRequest.newBuilder().uri(new URI("https://localhost:8000/greet")).build();
            HttpResponse<String> response = client.send(request, BodyHandlers.ofString());
            System.out.println(response.body());
        }
        catch(Exception e){
            e.printStackTrace();
        }
        
    }
}