package com.rutils;

import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;


public class Main{
    public static void main(String[] args){
        
        HttpClient client = HttpClient.newHttpClient();
        try{
            



            HttpRequest request = HttpRequest.newBuilder().uri(new URI("https://localhost:8000/greet")).build();
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            System.out.println(response.body());
        }
        catch(Exception e){}
        
    }
}