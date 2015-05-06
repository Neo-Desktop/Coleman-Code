Public Class PatternSearcher

    Private _searchResults As SearchResults = New SearchResults

    Public Property FileType As String
    Public Property IsCaseSensitive As Boolean
    Public Property Pattern As String

    Sub New(FT As String, ICS As Boolean, P As String)
        FileType = FT
        IsCaseSensitive = ICS
        Pattern = P
    End Sub

    Sub Search()

    End Sub


End Class