Public Class SearchResults

    Private _results As List(Of FoundResults) = New List(Of FoundResults)

    Sub addResult(input As FoundResults)
        _results.Add(input)
    End Sub

    Sub clearResults()
        _results.Clear()
    End Sub

    Function getResults() As List(Of FoundResults)
        Return _results
    End Function

End Class
