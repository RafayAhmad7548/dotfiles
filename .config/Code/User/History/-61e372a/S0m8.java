package com.rutils;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.nio.charset.StandardCharsets;
import java.security.KeyStore;

import javax.net.ssl.KeyManagerFactory;
import javax.net.ssl.SSLContext;
import javax.net.ssl.SSLParameters;

import org.hibernate.Session;
import org.hibernate.Transaction;
import org.json.JSONObject;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpsConfigurator;
import com.sun.net.httpserver.HttpsParameters;
import com.sun.net.httpserver.HttpsServer;;

public class Main{

    static HttpsServer server;

    static{
        try{
            KeyStore keyStore = KeyStore.getInstance("PKCS12");
            keyStore.load(Main.class.getClassLoader().getResourceAsStream("server.p12"), "ksserver7548".toCharArray());

            KeyManagerFactory kmf = KeyManagerFactory.getInstance(KeyManagerFactory.getDefaultAlgorithm());
            kmf.init(keyStore, "ksserver7548".toCharArray());

            SSLContext sslContext = SSLContext.getInstance("TLS");
            sslContext.init(kmf.getKeyManagers(), null, null);

            server = HttpsServer.create(new InetSocketAddress(8000), 0);
            server.setHttpsConfigurator(new HttpsConfigurator(sslContext){
                @Override
                public void configure(HttpsParameters params){
                    // InetSocketAddress remote = params.getClientAddress();
                    SSLContext c = getSSLContext();
                    SSLParameters sslParameters = c.getDefaultSSLParameters();
                    // if(remote.equals()){

                    // }
                    params.setSSLParameters(sslParameters);
                }
            });
        }
        catch(Exception e){
            e.printStackTrace();
        }

    }
    public static void main(String[] args){
        server.createContext("/login", new LoginHandler());
        server.setExecutor(null);
        server.start();
    }

    static class RegisterHandler implements HttpHandler{
        @Override
        public void handle(HttpExchange exchange) throws IOException{
            if("POST".equals(exchange.getRequestMethod())){

            }
            else{

            }

        }

    }

    static class LoginHandler implements HttpHandler{
        @Override
        public void handle(HttpExchange exchange) throws IOException{
            if("POST".equals(exchange.getRequestMethod())){
                String body = new String(exchange.getRequestBody().readAllBytes(), StandardCharsets.UTF_8);
                JSONObject jsonObject = new JSONObject(body);
                String username = jsonObject.getString("username");           
                String password = jsonObject.getString("password");

                String response = Integer.toString(1);

                Session session = HibernateUtil.getSessionfactory().openSession();
                Transaction tx = null;

                try{
                    tx = session.beginTransaction();
                    User user = session.get(User.class, username);
                    if(user != null){
                        if(user.getPassword() == password) response = Integer.toString(1); // successful verification
                        else response = Integer.toString(2); // incorrect password
                    }
                    else response = Integer.toString(0); // user not registered
                    tx.commit();
                }
                catch(Exception e){
                    if(tx != null) tx.rollback();
                    e.printStackTrace();
                }
                finally{
                    session.close();
                }

                exchange.sendResponseHeaders(200, response.length());
                OutputStream os = exchange.getResponseBody();
                os.write(response.getBytes());
                os.close();
            }
            else{
                exchange.sendResponseHeaders(405, -1);
            }
        }

    }
}