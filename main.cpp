#include <bits/stdc++.h>
#include "FindMaxFlow.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


int main(int argc, char* argv[])
{

    ifstream file;
    string path = "E:\\Study\\2 kurs\\4 semestr\\aistd\\CourseWorkClion\\input.txt";
    file.open(path);
    if(!file) throw runtime_error("File doesn't exist");

    vector<OneString> parseString;

    parseString = ParsingInputFile(file, parseString);

    vector<int> oneVertex = NumberOfVertices(parseString);

    int v = oneVertex.size();
    Graph g(v);

    vector<int> verticesInOrder;
    int start = 0;
    verticesInOrder = ConvertingChar_Number(oneVertex, verticesInOrder);
    int end = verticesInOrder.size();

    NetworkBuilding(parseString, oneVertex, verticesInOrder, g);

    cout << "Maximum flow is " << g.getMaxFlow(start, end) << endl;

    file.close();

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    return 0;
} 
