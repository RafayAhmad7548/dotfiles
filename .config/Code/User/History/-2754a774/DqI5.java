package com.rutils;

import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.security.cert.CertificateFactory;


public class Main{
    public static void main(String[] args){
        
        HttpClient client = HttpClient.newHttpClient();
        try{
            CertificateFactory cf = CertificateFactory.getInstance("X.509");




            HttpRequest request = HttpRequest.newBuilder().uri(new URI("https://localhost:8000/greet")).build();
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            System.out.println(response.body());
        }
        catch(Exception e){}
        
    }
}