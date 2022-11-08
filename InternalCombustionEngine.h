#pragma once
#include "Engine.h"
#include <vector>

class InternalCombustionEngine : public Engine
{
	double I {0.1}; // ������ ������� ���������
	std::vector<int> M {20, 75, 100, 105, 75, 0};// �������-�������� ����������� ��������� ������� M-
	std::vector<int> V {0, 75, 150, 200, 250, 300};// �� �������� �������� ��������� V
	int TOverhating {110};// ����������� ���������
	double Hm {0.01};// ����������� ����������� �������� ������� �� ��������� �������
	double Hv {0.0001};// ����������� ����������� �������� ������� �� �������� �������� ���������
	double C {0.1};// ����������� ����������� �������� ���������� �� ����������� ��������� � ���������� �����
	int Tenv{ 0 };
	double TEng = 0; //����������� ���������
	bool working;
	double Vh{ 0.0 };// �������� ������� ���������
	double Vc{ 0.0 };// �������� ���������� ���������
	double workedTime{ 0.0 };

public:

	InternalCombustionEngine (int Tenv);
	~InternalCombustionEngine() override;
	void EngineStart() override;
	void Working() override;
	void EngineStop() override;
	bool IsWorking() override;
	void setWorking(bool condition) override;
	double getTimeHasWorked() override;
	double getEngineTemperature() override;
	double getOverhatingTemperature() override;
};
