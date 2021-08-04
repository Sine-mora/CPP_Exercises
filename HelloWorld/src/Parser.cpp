#include "Parser.h"

Parser::Parser()
{
    // 0-5 figures
    m_vCurrGame = {
        {'a', 'a', 'a', 'b', 'a'}, {'c', 'c', 'd', 'a', 'c'}, {'d', 'e', 'a', 'a', 'd'}};
}

void Parser::CheckXml(const char* source)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(source);

    if (result)
    {
        std::cout << "XML [" << source << "] parsed without errors, attr value: ["
                  << doc.child("Line").attribute("id").value() << "]\n\n";
    }
    else
    {
        std::cout << "XML [" << source << "] parsed with errors, attr value: ["
                  << doc.child("Line").attribute("id").value() << "]\n"
                  << "Error description: " << result.description() << "\n"
                  << "Error offset: " << result.offset << "(error at [..."
                  << (source + result.offset) << "]\n\n";
    }
}

void Parser::LoadDocument()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("../xml/Lines.xml");
    std::cout << "Load result:" << result.description()
              << "Line 1 id = " << doc.child("Line").attribute("id").value() << std::endl;
}

void Parser::LoadErrorHandling()
{
    CheckXml("<Line id='20'><Reel>text</Reel></Line>");
}

bool Parser::Traverse(pugi::xml_node& lines)
{
    pugi::xml_document doc;
    if (!doc.load_file("../xml/Lines.xml"))
    {
        std::cerr << "Failed to load Lines.xml\n";
        return false;
    }
    lines = doc.child("Lines");
    return true;
}

void Parser::ReadXML()
{
    pugi::xml_node lines;
    // std::vector<std::vector<int>> vLines;
    // Vector2D<int> vLines;

    if (!Traverse(lines))
    {
        return;
    }

    for (pugi::xml_node line = lines.first_child(); line; line = line.next_sibling())
    {
        std::cout << "Line:";

        for (pugi::xml_attribute attr = line.first_attribute(); attr;
             attr = attr.next_attribute())
        {
            std::cout << " " << attr.name() << "=" << attr.value() << "\n";

            std::vector<int> vReels;
            for (pugi::xml_node reel = line.child("Reel"); reel;
                 reel = reel.next_sibling("Reel"))
            {
                std::cout << "Reel " << reel.attribute("index").as_int() << " ";

                pugi::xml_node position = reel.child("Position");
                std::cout << "Position " << position.attribute("index").as_int();
                std::cout << std::endl;

                vReels.push_back(static_cast<char>(position.attribute("index").as_int()));
            }
            m_vWinLines.push_back(vReels);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "\nReel indexes to win a line " << std::endl;

    int nCurrLine = 0;
    for (auto& vLine : m_vWinLines)
    {
        std::cout << "Line[" << nCurrLine << "]: ";
        for (int j : vLine)
        {
            std::cout << j << " ";
        }
        nCurrLine++;
        std::cout << std::endl;
    }
}

void Parser::CalcAllLines()
{
    // Reel index
    // Reel position

    std::cout << "\nFigures to Indexes" << std::endl;
    int reelPos = 0;
    for (std::size_t lineIndex = 0; lineIndex < m_vWinLines.size(); lineIndex++)
    {
        std::vector<char> vReels;
        std::cout << "Line[" << lineIndex << "] has figures: ";
        for (std::size_t reelIndex = 0; reelIndex < m_vWinLines.at(lineIndex).size();
             reelIndex++)
        {
            reelPos = m_vWinLines.at(lineIndex).at(reelIndex);
            vReels.push_back(m_vCurrGame.at(reelPos).at(reelIndex));
            std::cout << static_cast<char>(m_vCurrGame.at(reelPos).at(reelIndex)) << " ";
        }
        m_vPrsLines.push_back(vReels);
        std::cout << std::endl;
    }
}

void Parser::PrintCurrentResults()
{
    std::cout << "\nCurrent figures" << std::endl;
    for (std::size_t i = 0; i < m_vCurrGame.size(); i++)
    {
        for (std::size_t j = 0; j < m_vCurrGame.at(i).size(); j++)
        {
            std::cout << static_cast<char>(m_vCurrGame.at(i).at(j)) << " ";
        }
        std::cout << std::endl;
    }
}

void Parser::ParsePayTable()
{
    std::cout << std::endl;
    Vector2D<char> vStoreChars = {};
    int k = 0;
    std::cout << "Line SSS = " << static_cast<char>(m_vPrsLines.at(2).at(0)) << "\n";
    // Variant 1

    for (auto& vPrsLine : m_vPrsLines)
    {
        std::vector<char> figsAt = {};
        uint id = 0;
        int count = 0;

        for (std::size_t jRow = 0; jRow < vPrsLine.size(); jRow++)
        {
            char figID = vPrsLine.at(jRow);
            if (figID == m_vPrsLines.at(jRow).at(id))
            {
                figsAt.push_back(figID);
                count++;
            }

            m_vWinLines.size();

            std::cout << static_cast<char>(vPrsLine.at(jRow)) << " ";
        }
        vStoreChars.push_back(figsAt);
        k++;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    for (const auto& i : vStoreChars)
    {
        for (char j : i)
        {
            std::cout << "Test: " << static_cast<char>(j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nWinning:\n";
    for (auto& i : m_vCurrGame)
    {
        m_cWinElement = i.at(0);
        for (char j : i)
        {
            if (m_cWinElement == j)
                m_nCountElement++;
            m_cWinElement = j;
        }
        std::cout << "Win Element: " << m_cWinElement << " Count: " << m_nCountElement
                  << "\n";
        m_nCountElement = 0;
    }
    std::cout << "-\n";

    for (std::size_t i = 0; i < m_vWinLines.size(); i++)
    {
        for (std::size_t j = 0; j < m_vWinLines[i].size(); j++)
        {
            m_cWinElement = (m_vCurrGame.at(m_vWinLines[i][j]).at(0));
            if(m_vCurrGame.at(m_vWinLines[i][j]).at(j) == 'a')
            {
                std::cout <<"\n";
            }
        }
    }
}
