package com.xworkz.election.service;

import java.util.List;

import com.xworkz.election.dto.ElectionDto;
import com.xworkz.election.repo.ElectionRepo;
import com.xworkz.election.repo.ElectionRepoImpl;

public class ElectionServiceImpl implements ElectionService {

	ElectionRepo repo = new ElectionRepoImpl();

	@Override
	public boolean save(ElectionDto dto) {
		if (dto != null) {
			if (dto.getName().length() == 0) {

				if (dto.getPincode() >= 6) {
					repo.save(dto);

					return true;
				}
			}
		}
		return false;
	}

	@Override
	public List<ElectionDto> readAll() {

		return repo.readAll();
	}

}
