package com.practice;

import javax.transaction.Transaction;

import org.hibernate.Session;

public class Main{
    public static void main(String[] args){
        
        Session session = HibernateUtil.getSessionfactory().openSession();
        Transaction tx = null;
        try{
            tx = session.beginTransaction();
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
        Student arqam = new Student(232608, "Arqam Zulfiqar", 2.1);
        System.out.println("Arqam Made\n");
        session.save(arqam);
        session.getTransaction().commit();
        session.close();
        System.out.println("Arqam Saved\n");

        HibernateUtil.shutdown();
    }
}