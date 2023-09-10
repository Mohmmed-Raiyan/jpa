package com.xworkz.election.repo;

import java.util.List;
import java.util.Properties;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

import com.xworkz.election.dto.ElectionDto;

public class ElectionRepoImpl implements ElectionRepo {
	Properties props = new Properties();

	EntityManagerFactory emf = Persistence.createEntityManagerFactory("servlets", props);
	EntityManager em = emf.createEntityManager();

	public boolean save(ElectionDto dto) {

		if (em == null) {
			em.getTransaction().begin();
			em.persist(dto);
			em.getTransaction().commit();
			return true;
		}
		return false;

	}

	public List<ElectionDto> readAll() {
		if (em != null) {
			em.getTransaction().begin();
			List list = em.createNamedQuery("readAll").getResultList();
			list.clear();
			em.getTransaction().commit();
			return list;
		}
		return null;
	}

}
