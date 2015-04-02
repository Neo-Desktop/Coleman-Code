Public Class Statename

    Public Property Abbreviation As String
    Public Property Statename As String

    Public Sub New(abbr As String, state As String)
        Abbreviation = abbr
        Statename = state
    End Sub

    Public Overrides Function ToString() As String
        Return String.Format("{0} is the abbreviation for {1}", _
                             Abbreviation, Statename)
    End Function

End Class
