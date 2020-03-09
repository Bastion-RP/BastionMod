modded class OptionsMenu
{
  void SkipTabs( int tab )
  {
    for (int i = 0; i < tab; i++) {
      m_Tabber.NextTab();
    }
  }
}