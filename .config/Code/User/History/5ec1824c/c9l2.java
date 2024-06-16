package com.practice;

import org.hibernate.Session;

public class Main{
    public static void main(String[] args){
        
        Session session = HibernateUtil.getSessionfactory().openSession();
        Student arqam = new Student(232608, "Arqam Zulfiqar", 2.1);
        System.out.println("Arqam Made\n");
        session.save(arqam);
        session.getTransaction().commit();
        session.close();
        System.out.println("Arqam Saved\n");

        HibernateUtil.shutdown();
    }
}