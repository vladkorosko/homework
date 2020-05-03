#include "Structs.h"

vector<PointXYZ> Find_by_x(vector<PointXYZ> vector_points, int x_position)
{
	vector<PointXYZ> res;
	for (int i = 0; i < vector_points.size(); i++)
		if (vector_points[i].x_pos == x_position)
			res.push_back(vector_points[i]);
	return res;
}

vector<PointXYZ> Find_by_y(vector<PointXYZ> vector_points, int y_position)
{
	vector<PointXYZ> res;
	for (int i = 0; i < vector_points.size(); i++)
		if (vector_points[i].y_pos == y_position)
			res.push_back(vector_points[i]);
	return res;
}

vector<PointXYZ> Find_by_z(vector<PointXYZ> vector_points, int z_position)
{
	vector<PointXYZ> res;
	for (int i = 0; i < vector_points.size(); i++)
		if (vector_points[i].z_pos == z_position)
			res.push_back(vector_points[i]);
	return res;
}

vector<PointXYZ> Find_by_x_in_range(vector<PointXYZ> vector_points, int x_first, int x_second)
{
	vector<PointXYZ> res;
	for (int i = 0; i < vector_points.size(); i++)
		if ((vector_points[i].x_pos >= x_first && vector_points[i].x_pos <= x_second) || (vector_points[i].x_pos <= x_first && vector_points[i].x_pos >= x_second))
			res.push_back(vector_points[i]);
	return res;
}

vector<PointXYZ> Find_by_y_in_range(vector<PointXYZ> vector_points, int y_first, int y_second)
{
	vector<PointXYZ> res;
	for (int i = 0; i < vector_points.size(); i++)
		if ((vector_points[i].y_pos >= y_first && vector_points[i].y_pos <= y_second) || (vector_points[i].y_pos <= y_first && vector_points[i].y_pos >= y_second))
			res.push_back(vector_points[i]);
	return res;
}

vector<PointXYZ> Find_by_z_in_range(vector<PointXYZ> vector_points, int z_first, int z_second)
{
	vector<PointXYZ> res;
	for (int i = 0; i < vector_points.size(); i++)
		if ((vector_points[i].z_pos >= z_first && vector_points[i].z_pos <= z_second) || (vector_points[i].z_pos <= z_first && vector_points[i].z_pos >= z_second))
			res.push_back(vector_points[i]);
	return res;
}