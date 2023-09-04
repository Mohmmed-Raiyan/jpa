package com.xworkz.account_holder_details.controller;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;

import com.xworkz.account_holder_details.entity.AccountEntity;

public class Inseration {

	public static void main(String[] args) {

		// AccountEntity entity = new AccountEntity("pavan", "bs", "pavan@gmail.com",
		// 1234567890566L, "25-01-2000", 100000, "kadur", "BCA", "O+", 978907890466L,
		// "saving", true);
		AccountEntity entity2 = new AccountEntity("Sanjay", "S", "saunjay@gmail.com", 7889098678L, "22-5-2000", 400000,
				"blr", "BA", "A+", 12345678907890L, "current", true);
		AccountEntity entity3 = new AccountEntity("Chandan", "gowda", "chandan@gmail.com", 99984567890L, "2-12-2002",
				250000, "blr", "BA", "A+", 1235378907890L, "current", true);
		AccountEntity entity4 = new AccountEntity("Giresh", "Nayak", "girish@gmail.com", 12345432890L, "25-2-89",
				500000, "blr", "BA", "A+", 1234435907890L, "saving", true);
		AccountEntity entity5 = new AccountEntity("Dharashan", "Raghu", "raghu@gmail.com", 2134657890L, "22-12-01",
				500000, "blr", "BA", "A+", 12342545907890L, "joinnt", true);

		EntityManagerFactory factory = Persistence.createEntityManagerFactory("com.xworkz");
		EntityManager manager = factory.createEntityManager();
		EntityTransaction transaction = manager.getTransaction();
		transaction.begin();

		manager.persist(entity3);
		manager.persist(entity4);
		manager.persist(entity5);

		transaction.commit();
		manager.close();
	}

}
