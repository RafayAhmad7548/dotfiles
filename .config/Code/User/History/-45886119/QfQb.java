package com.practice;

import org.hibernate.Transaction;

import org.hibernate.Session;

public class Main{
    public static void main(String[] args){
        
        Session session = HibernateUtil.getSessionfactory().openSession();
        Transaction tx = null;
        try{
            tx = session.beginTransaction();
            Student newStudent = new Student(2340, "hassan", 4);
            session.save(newStudent);
            tx.commit();
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