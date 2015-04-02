Module Options

    Private _Directory As String
    Public Property Directory() As String
        Get
            Return _Directory
        End Get
        Set(ByVal value As String)
            _Directory = value
        End Set
    End Property

    Private _PlaylistLength As Integer
    Public Property PlaylistLength() As Integer
        Get
            Return _PlaylistLength
        End Get
        Set(ByVal value As Integer)
            _PlaylistLength = value
        End Set
    End Property

    Private _SongGap As Integer
    Public Property SongGap() As Integer
        Get
            Return _SongGap
        End Get
        Set(ByVal value As Integer)
            _SongGap = value
        End Set
    End Property

    Public Files As List(Of FileData)
    Sub AddFile(in as String)

    End Sub





End Module
