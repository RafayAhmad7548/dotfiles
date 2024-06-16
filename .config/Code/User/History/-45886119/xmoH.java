package com.practice;

import org.hibernate.Transaction;

import org.hibernate.Session;

public class Main{
    public static void main(String[] args){
        
        Session session = HibernateUtil.getSessionfactory().openSession();
        Transaction tx = null;
        try{
            tx = session.beginTransaction();
            Student arqam = session.get(Student.class, 232609);
            session.delete(arqam);
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