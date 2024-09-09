package com.rutils;

import java.io.InputStream;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.security.KeyStore;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;


public class Main{
    public static void main(String[] args){
        
        HttpClient client = HttpClient.newHttpClient();
        try{
            CertificateFactory cf = CertificateFactory.getInstance("X.509");
            InputStream certInputStream = Main.class.getResourceAsStream("/mycertificate.crt");
            X509Certificate caCert = (X509Certificate)cf.generateCertificate(certInputStream);

            KeyStore keyStore = KeyStore.getInstance(KeyStore.getDefaultType());
            keyStore.load(certInputStream, caCert);



            HttpRequest request = HttpRequest.newBuilder().uri(new URI("https://localhost:8000/greet")).build();
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            System.out.println(response.body());
        }
        catch(Exception e){}
        
    }
}