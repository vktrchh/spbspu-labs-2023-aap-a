#include "StringInputer.hpp"

#include <iostream>

zhalilov::StringInputer::StringInputer():
  m_string(nullptr),
  m_dataInd(0),
  m_strSize(0)
{}

void zhalilov::StringInputer::resize()
{
  char *temp = new(std::nothrow) char(m_strSize * 2);
  if (temp == nullptr)
  {
    delete m_string;
    m_string = nullptr;
    return;
  }
  for (int i = 0; i < m_strSize; i++)
  {
    temp[i] = m_string[i];
  }
  delete m_string;
  m_string = temp;
  temp = nullptr;
  m_strSize *= 2;
}

char *zhalilov::StringInputer::operator()()
{
  delete m_string;
  m_dataInd = 0;
  m_string = new(std::nothrow) char(100);
  if (!m_string)
  {
    return nullptr;
  }
  m_strSize = 100;

  char temp = 0;
  while (std::cin >> temp)
  {
    m_string[m_dataInd] = temp;
    if (temp == '\0')
    {
      break;
    }
    if (m_strSize == m_dataInd + 1)
    {
      resize();
      if (!m_string)
      {
        break;
      }
    }
    m_dataInd++;
  }
  return m_string;
}
