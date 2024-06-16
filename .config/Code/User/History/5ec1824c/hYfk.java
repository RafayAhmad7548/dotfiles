package com.practice;

import org.hibernate.Transaction;

import org.hibernate.Session;

public class Main{
    public static void main(String[] args){
        
        Session session = HibernateUtil.getSessionfactory().openSession();
        Transaction tx = null;
        try{
            tx = session.beginTransaction();
            Student arqam = new Student(232608, "Arqam Zulfiqar", 2.1);
            System.out.println("Arqam Made\n");
            session.save(arqam);
            tx.commit();
            System.out.println("Arqam Saved\n");
        }
        catch(Exception e){
            if(tx != null){
                tx.rollback();
            }
            e.printStackTrace();
        }
        finally{
            session.close();
        }

        HibernateUtil.shutdown();
    }
}