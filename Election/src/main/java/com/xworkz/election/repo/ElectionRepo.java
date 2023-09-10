package com.xworkz.election.repo;

import java.util.List;

import com.xworkz.election.dto.ElectionDto;

public interface ElectionRepo {

	public boolean save(ElectionDto dto);

	public List<ElectionDto> readAll();

}
