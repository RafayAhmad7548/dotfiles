package com.rutils;

import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

public class HibernateUtil{
    private static final SessionFactory sessionFactory = buildSessionFactory();

    private static SessionFactory buildSessionFactory(){
        try{
            return new Configuration().configure().buildSessionFactory();
        }
        catch(Throwable e){
            System.err.println("Session Factory creation failed" + e);
            throw new ExceptionInInitializerError(e);
        }
    }

    public static SessionFactory getSessionfactory(){
        return sessionFactory;
    }

    public static void shutdown(){
        getSessionfactory().close();
    }

}
