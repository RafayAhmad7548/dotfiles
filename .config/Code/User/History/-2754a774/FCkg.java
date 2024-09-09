package com.rutils;

import java.net.URI;
import java.net.URISyntaxException;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;

public class Main{
    public static void main(String[] args){
        HttpClient client = HttpClient.newHttpClient();
        try{
            HttpRequest request = HttpRequest.newBuilder().uri(new URI("http://localhost:8000/greet")).build();
        }
        catch (URISyntaxException e){
            e.printStackTrace();
        }
    }
}