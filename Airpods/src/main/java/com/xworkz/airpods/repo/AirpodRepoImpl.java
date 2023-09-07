package main.java.com.xworkz.airpods.repo;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;
import javax.persistence.Query;

import main.java.com.xworkz.airpods.dto.AirpodsDto;

public class AirpodRepoImpl implements AirpodsRepo {

	EntityManagerFactory emf = Persistence.createEntityManagerFactory("com.xworkz");

	EntityManager em = emf.createEntityManager();

	public boolean store(AirpodsDto dto1) {
		System.out.println("invoking store method");

		if (em != null) {

			EntityTransaction transaction = em.getTransaction();
			em.getTransaction().begin();
			em.persist(dto1);
			System.out.println("repo=" + dto1);
			em.close();
			transaction.commit();
			return true;
		}

		return false;
	}

	public boolean updateColorByName(String color, String name) {
		if (em != null) {
			EntityTransaction transaction = em.getTransaction();
			em.getTransaction();
			transaction.begin();
			Query query = em.createNamedQuery("updateColorbyName");
			query.setParameter("col", color);
			query.setParameter("nm", name);
			int i = query.executeUpdate();
			transaction.commit();
			em.close();
			return true;

		}
		return false;
	}

	public boolean deleteByPrice(int price) {
		System.out.println("delete method");
		if (em != null) {
			em.getTransaction().begin();
			Query query = em.createNamedQuery("deleteByPrice");
			query.setParameter("pr", price);
			int r=query.executeUpdate();
			em.getTransaction().commit();
			
			em.close();
			return true;

		}
		return false;
	}

	public List<AirpodsDto> readAll() {
		
		Query query = em.createNamedQuery("readAll");
		List<AirpodsDto> list = query.getResultList();
		
		return list;
	}

}
