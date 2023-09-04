package com.xworkz.account_holder_details.controller;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class Update {

	public static void main(String[] args) {

		EntityManagerFactory factory=Persistence.createEntityManagerFactory("com.Xworkz");
	}

}
