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

    Public ExtensionsList As String() = {".3gp", ".act", ".aiff", ".aac", ".amr", ".au", ".awb", ".dct", ".dss", ".dvf", ".flac", ".gsm", ".iklax", ".ivs", ".m4a", ".m4p", ".mmf", ".mp3", ".mpc", ".msv", ".ogg", ".oga", ".opus", ".ra", ".rm", ".raw", ".sln", ".tta", ".vox", ".wav", ".wma", ".wv"}

    Public PlaylistTime As Integer = 0
    Public TotalTime As Integer = 0

End Module
